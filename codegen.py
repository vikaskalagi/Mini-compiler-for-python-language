
import re
import sys

inputFile = "output_file.txt"



def is_id(s): return bool(re.match(r"^[A-Za-z][A-Za-z0-9_]*$", s))


def is_temp(s): return bool(re.match(r"^r[0-9]*$", s))


def is_label(s): return bool(re.match(r"^L[0-9]*$", s))


def gen_op_code(op, dest, reg1, reg2,out):
    code = ""
    if op == '>':
        code = "CMP {}, {}"
        out.append(code.format(reg1, reg2))
        code = "MOV {}, #1"
        out.append(code.format(dest))
        code = "MOVLEZ {}, #0"
        out.append(code.format(dest))
    elif op == '+':
        code = "ADD {}, {}, {}"
        out.append(code.format(dest, reg1, reg2))
    elif op == '*':
        code = "MUL {}, {}, {}"
        out.append(code.format(dest, reg1, reg2))
    elif op == '/':
        code = "DIV {}, {}, {}"
        out.append(code.format(dest, reg1, reg2))
    elif op == '<':
        code = "CMP {}, {}"
        out.append(code.format(reg1, reg2))
        code = "MOV {}, #1"
        out.append(code.format(dest))
        code = "MOVGEZ {}, #0"
        out.append(code.format(dest))
    elif op == '-':
        code = "SUBS {}, {}, {}"
        out.append(code.format(dest, reg1, reg2))
    elif op == 'or':
        code = "ORR {}, {}, {}"
        out.append(code.format(dest, reg1, reg2))
    elif op == '<=':
        code = "CMP {}, {}"
        out.append(code.format(reg1, reg2))
        code = "MOV {}, #1"
        out.append(code.format(dest))
        code = "MOVGZ {}, #0"
        out.append(code.format(dest))
    elif op == '>=':
        code = "CMP {}, {}"
        out.append(code.format(reg1, reg2))
        code = "MOV {}, #1"
        out.append(code.format(dest))
        code = "MOVLZ {}, #0"
        out.append(code.format(dest))
    elif op == 'and':
        code = "AND {}, {}, {}"
        out.append(code.format(dest, reg1, reg2))
    elif op == '==':
        code = "CMP {}, {}"
        out.append(code.format(reg1, reg2))
        code = "MOV {}, #0"
        out.append(code.format(dest))
        code = "MOVEZ {}, #1"
        out.append(code.format(dest))

    return out


def gen_bool_code(op, reg, label):
    code = ""
    if op == '>=':
        code = "BLZ {}, {}"
    elif op == '!=':
        code = "BEZ {}, {}"
    elif op == '<=':
        code = "BGZ {}, {}"
    elif op == '==' or op == '=':
        code = "BNEZ {}, {}"
    elif op == '<':
        code = "BGEZ {}, {}"
    elif op == '>':
        code = "BLEZ {}, {}"
    
    return code.format(reg, label)


def generate(lines):
    out = []
    bool_expr = {}

    for line in lines:
        tokens = line.split()
        #print(tokens)
        if len(tokens) == 2 and tokens[0] == "goto":
            out.append("BR " + tokens[1])
        elif len(tokens) == 3:
            if tokens[2].isdigit():
                out.append("MOV $R0, #" + tokens[2])
                out.append("ST {}, $R0".format(tokens[0]))
            elif(tokens[2]=='true'):
                out.append("LD $R0, #1")
                out.append("ST {}, $R0".format(tokens[0]))
            elif(tokens[2]=='False'):
                out.append("LD $R0, #0")
                out.append("ST {}, $R0".format(tokens[0]))   
            elif is_id(tokens[2]):
                out.append("LD $R0, " + tokens[2])
                out.append("MOV $R1, $R0")
                out.append("ST {}, $R1".format(tokens[0]))
        elif len(tokens) == 4:
            expr = tokens[1]
            if ('>' in expr or '<' in expr):
                #print("len 4", expr,tokens)
                out.append("LD $R0, " + expr[0])
                out.append("LD $R1, #" + expr[2:])
                out=gen_op_code('-', "$R0", "$R0", "$R1",out)
                out.append(gen_bool_code(
                    expr[1], "$R0", tokens[3].rstrip(':')))
            else:
                out.append("LD $R0, " + tokens[1])
                #bool_op = bool_expr[tokens[1]][1]
                out.append("CMP $R0 , 0")
                out.append("BEZ "+tokens[3])
        elif len(tokens) == 5:
            if is_id(tokens[2]) and is_id(tokens[4]):
                #if tokens[3] in (arithop):
                out.append("LD $R0, " + tokens[2])
                out.append("LD $R1, " + tokens[4])
                out=gen_op_code(tokens[3], "$R2", "$R0", "$R1",out)
                out.append("ST {}, $R2".format(tokens[0]))

            elif is_id(tokens[2]) and tokens[4].isdigit():
                #if tokens[3] in (arithop):
                out.append("LD $R0, " + tokens[2])
                out.append("MOV $R1, #" + tokens[4])
                #print(out,"ui",tokens)
                out=gen_op_code(tokens[3], "$R2", "$R0", "$R1",out)
                #print(out,"df")
                out.append("ST {}, $R2".format(tokens[0]))
                
            elif is_id(tokens[4]) and tokens[2].isdigit():
                out.append("MOV $R0, #" + tokens[2])
                out.append("LD $R1, " + tokens[4])
                out=gen_op_code(
                    tokens[3], "$R2", "$R1", "$R0",out)
                out.append("ST {}, $R2".format(tokens[0]))
            else:
                out.append("MOV $R0, #" + tokens[2])
                out.append("MOV $R1, #" + tokens[4])
                out=gen_op_code(
                    tokens[3], "$R2", "$R1", "$R0",out)
                out.append("ST {}, $R2".format(tokens[0]))   
        
        else:
            out.append("")
            out.append(line)
            #print(line)
    return out


if __name__ == "__main__":
    if len(sys.argv) == 2:
        inputFile = sys.argv[1]

    lines = []

    with open(inputFile, 'r') as f:
        lines.extend(map(lambda x: x.rstrip('\n'), f.readlines()))

    out = generate(lines)

    for line in out:
        print(line)
