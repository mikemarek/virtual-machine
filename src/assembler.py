import sys
import struct
from Opcodes import *
from Syntax import *
from DataTypes import *

class Assembler():
    #
    debug = False;


    #
    def __init__(self, *files):
        #
        print

        # two's compliment test
        """number = 2420
        invnum = -2420
        print number
        print ~invnum + 1
        print self.stob(number)
        print self.stob(invnum)
        print"""
        #

        #
        for stream in self.traverse(files):
            #
            running  = True
            tokens   = list()
            bytecode = list()
            gotos    = list()
            indices  = list()
            labels   = {}
            methods  = {}

            # parse name of file and check for valid input
            filename = stream.split('.')[0]
            filename.strip('\r\n .')
            if filename == '':
                print "file \'" + stream + "\' is an invalid file name."
                continue

            print "<compiling " + stream + ">"

            # create token stream from file stream
            with open(stream) as file:
                #
                lines = file.readlines()
                for l in range(len(lines)):
                    token = lines[l].strip('\r\n')
                    token = token.split(' ')
                    token = self.decomment(token)
                    for t in token:
                        t = t.strip(' \t')
                        if t != '':
                            tokens.append(t)
                file.close()

            # parse tokens into bytecode (blank labels)
            i = 0
            while i < len(tokens):
                #
                if tokens[i] == Syntax.BPUSH:
                    val = tokens[i+1] # int(tokens[i+1])
                    val = ord(val) if val.isalpha() else int(val)

                    self.writebyte(int(Opcodes.BPUSH, 16), bytecode)
                    self.writebyte(val, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.SPUSH:
                    val = int(tokens[i+1])
                    self.writebyte(int(Opcodes.SPUSH, 16), bytecode)
                    self.writeshort(val, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.IPUSH:
                    val = int(tokens[i+1])
                    self.writebyte(int(Opcodes.IPUSH, 16), bytecode)
                    self.writeint(val, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.FPUSH:
                    val = float(tokens[i+1])
                    self.writebyte(int(Opcodes.FPUSH, 16), bytecode)
                    self.writefloat(val, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.DUP:
                    self.writebyte(int(Opcodes.DUP, 16), bytecode)
                    i = i + 1
                elif tokens[i] == Syntax.DUP2:
                    self.writebyte(int(Opcodes.DUP2, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SWAP:
                    self.writebyte(int(Opcodes.SWAP, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SWAP2:
                    self.writebyte(int(Opcodes.SWAP2, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BSTORE:
                    val = int(tokens[i+1])
                    self.writebyte(int(Opcodes.BSTORE, 16), bytecode)
                    self.writeshort(val, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.SSTORE:
                    val = int(tokens[i+1])
                    self.writebyte(int(Opcodes.SSTORE, 16), bytecode)
                    self.writeshort(val, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.ISTORE:
                    val = int(tokens[i+1])
                    self.writebyte(int(Opcodes.ISTORE, 16), bytecode)
                    self.writeshort(val, bytecode)
                    i = i + 2
                elif tokens[i] == Syntax.FSTORE:
                    val = int(tokens[i+1])
                    self.writebyte(int(Opcodes.FSTORE, 16), bytecode)
                    self.writeshort(val, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.BLOAD:
                    val = int(tokens[i+1])
                    self.writebyte(int(Opcodes.BLOAD, 16), bytecode)
                    self.writeshort(val, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.SLOAD:
                    val = int(tokens[i+1])
                    self.writebyte(int(Opcodes.SLOAD, 16), bytecode)
                    self.writeshort(val, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.ILOAD:
                    val = int(tokens[i+1])
                    self.writebyte(int(Opcodes.ILOAD, 16), bytecode)
                    self.writeshort(val, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.FLOAD:
                    val = int(tokens[i+1])
                    self.writebyte(int(Opcodes.FLOAD, 16), bytecode)
                    self.writeshort(val, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.BADD:
                    self.writebyte(int(Opcodes.BADD, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BSUB:
                    self.writebyte(int(Opcodes.BSUB, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BMUL:
                    self.writebyte(int(Opcodes.BMUL, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BDIV:
                    self.writebyte(int(Opcodes.BDIV, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BMOD:
                    self.writebyte(int(Opcodes.BMOD, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BNOT:
                    self.writebyte(int(Opcodes.BNOT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BAND:
                    self.writebyte(int(Opcodes.BAND, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BOR:
                    self.writebyte(int(Opcodes.BOR, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BXOR:
                    self.writebyte(int(Opcodes.BXOR, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SADD:
                    self.writebyte(int(Opcodes.SADD, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SSUB:
                    self.writebyte(int(Opcodes.SSUB, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SMUL:
                    self.writebyte(int(Opcodes.SMUL, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SDIV:
                    self.writebyte(int(Opcodes.SDIV, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SMOD:
                    self.writebyte(int(Opcodes.SMOD, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SNOT:
                    self.writebyte(int(Opcodes.SNOT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SAND:
                    self.writebyte(int(Opcodes.SAND, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SOR:
                    self.writebyte(int(Opcodes.SOR, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SXOR:
                    self.writebyte(int(Opcodes.CXOR, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.IADD:
                    self.writebyte(int(Opcodes.IADD, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.ISUB:
                    self.writebyte(int(Opcodes.ISUB, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.IMUL:
                    self.writebyte(int(Opcodes.IMUL, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.IDIV:
                    self.writebyte(int(Opcodes.IDIV, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.IMOD:
                    self.writebyte(int(Opcodes.IMOD, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.INOT:
                    self.writebyte(int(Opcodes.INOT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.IAND:
                    self.writebyte(int(Opcodes.IAND, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.IOR:
                    self.writebyte(int(Opcodes.IOR, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.IXOR:
                    self.writebyte(int(Opcodes.IXOR, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FADD:
                    self.writebyte(int(Opcodes.FADD, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FSUB:
                    self.writebyte(int(Opcodes.FSUB, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FMUL:
                    self.writebyte(int(Opcodes.FMUL, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FDIV:
                    self.writebyte(int(Opcodes.FDIV, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FMOD:
                    self.writebyte(int(Opcodes.FMOD, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FNOT:
                    self.writebyte(int(Opcodes.FNOT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FAND:
                    self.writebyte(int(Opcodes.FAND, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FOR:
                    self.writebyte(int(Opcodes.FOR, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FXOR:
                    self.writebyte(int(Opcodes.FXOR, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.GOTO:
                    self.writebyte(int(Opcodes.GOTO, 16), bytecode)
                    gotos.append([len(bytecode), tokens[i+1]])
                    self.writeshort(0, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.LABEL:
                    labels[tokens[i+1]] = len(bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.IFE:
                    self.writebyte(int(Opcodes.IFE, 16), bytecode)
                    gotos.append([len(bytecode), tokens[i+1]])
                    self.writeshort(0, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.IFN:
                    self.writebyte(int(Opcodes.IFE, 16), bytecode)
                    gotos.append([len(bytecode), tokens[i+1]])
                    self.writeshort(0, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.IFNE:
                    self.writebyte(int(Opcodes.IFNE, 16), bytecode)
                    gotos.append([len(bytecode), tokens[i+1]])
                    self.writeshort(0, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.IFLT:
                    self.writebyte(int(Opcodes.IFLT, 16), bytecode)
                    gotos.append([len(bytecode), tokens[i+1]])
                    self.writeshort(0, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.IFLE:
                    self.writebyte(int(Opcodes.IFLE, 16), bytecode)
                    gotos.append([len(bytecode), tokens[i+1]])
                    self.writeshort(0, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.IFGT:
                    self.writebyte(int(Opcodes.IFGT, 16), bytecode)
                    gotos.append([len(bytecode), tokens[i+1]])
                    self.writeshort(0, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.IFGE:
                    self.writebyte(int(Opcodes.IFGE, 16), bytecode)
                    gotos.append([len(bytecode), tokens[i+1]])
                    self.writeshort(0, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.DEFINE:
                    name          = tokens[i+1]
                    param         = int(tokens[i+2])
                    local         = int(tokens[i+3])
                    methods[name] = len(methods)

                    self.writebyte(int(Opcodes.DEFINE, 16), bytecode)
                    indices.append([len(bytecode), name])
                    self.writeshort(0, bytecode)
                    self.writeshort(param, bytecode)
                    self.writeshort(local, bytecode)

                    for p in range(param + local):
                        if tokens[i+4+p] == Syntax.BYTE:
                            self.writebyte(int(DataTypes.BYTE, 16), bytecode)
                        if tokens[i+4+p] == Syntax.SHORT:
                            self.writebyte(int(DataTypes.SHORT, 16), bytecode)
                        if tokens[i+4+p] == Syntax.INT:
                            self.writebyte(int(DataTypes.INT, 16), bytecode)
                    i = i + param + local + 4
                #
                elif tokens[i] == Syntax.INVOKE:
                    self.writebyte(int(Opcodes.INVOKE, 16), bytecode)
                    indices.append([len(bytecode), tokens[i+1]])
                    self.writeshort(0, bytecode)
                    i = i + 2
                #
                elif tokens[i] == Syntax.RETURN:
                    self.writebyte(int(Opcodes.RETURN, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BRETURN:
                    self.writebyte(int(Opcodes.BRETURN, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SRETURN:
                    self.writebyte(int(Opcodes.SRETURN, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.IRETURN:
                    self.writebyte(int(Opcodes.IRETURN, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FRETURN:
                    self.writebyte(int(Opcodes.FRETURN, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BPRINT:
                    self.writebyte(int(Opcodes.BPRINT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SPRINT:
                    self.writebyte(int(Opcodes.SPRINT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.IPRINT:
                    self.writebyte(int(Opcodes.IPRINT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FPRINT:
                    self.writebyte(int(Opcodes.FPRINT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.BPROMPT:
                    self.writebyte(int(Opcodes.BPROMPT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.SPROMPT:
                    self.writebyte(int(Opcodes.SPROMPT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.IPROMPT:
                    self.writebyte(int(Opcodes.IPROMPT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.FPROMPT:
                    self.writebyte(int(Opcodes.FPROMPT, 16), bytecode)
                    i = i + 1
                #
                elif tokens[i] == Syntax.PASS:
                    self.writebyte(int(Opcodes.PASS, 16), bytecode)
                    i = i + 1
                else:
                    # i = i + 1
                    print "INVALID TOKEN! line:" + str(i) + " " + tokens[i]
                    print "terminating..."
                    running = False
                    break

            if not running:
                print
                continue

            # calculate label positions and write to bytecode array
            # calculate method flags and write to bytecode array
            for i in range(len(gotos)):
                bytecode[gotos[i][0]+1] = labels[gotos[i][1]] & 255
                bytecode[gotos[i][0]] = (labels[gotos[i][1]] >> 8) & 255
            for i in range(len(indices)):
                bytecode[indices[i][0]+1] = methods[indices[i][1]] & 255
                bytecode[indices[i][0]] = (methods[indices[i][1]] >> 8) & 255

            print "outputting to \"" + filename + ".bin\""

            # write bytecode to file
            with open(filename + '.bin', 'wb') as file:
                for byte in range(len(bytecode)):
                    file.write(b'%c' % bytecode[byte])
                file.close()

            # just printing some bytecode, nothing to see here
            if self.debug == True:
                print "bytes: " + str(len(bytecode))
                for i in range(len(bytecode)):
                    print bytecode[i]

            print "<compilation complete>"
            print

    #
    # write byte to bytecode array
    def writebyte(self, b, a):
        if b < -1:
            b = 0
        elif b > 255:
            b = 255
        a.append(b)


    #
    # write signed short integer value (2 bytes; big-Endian to bytecode array)
    def writeshort(self, s, a):
        for b in list( reversed( bytearray(struct.pack("h", s)) ) ): # self.stob(s):
            a.append(b)


    #
    # write signed integer value (4 bytes; big-Endian) to bytecode array
    def writeint(self, i, a):
        ba = list( reversed( bytearray(struct.pack("i", i)) ) )
        for b in ba: # self.itob(i):
            a.append(b)


    #
    # write signed floating-point number (4 bytes; big-Endian) to bytecode array
    def writefloat(self, f, a):
        for b in bytearray(struct.pack("f", f)): # self.ftob(f):
            a.append(b)


    #
    def decomment(self, line):
        for i in range(len(line)):
            if line[i] == Syntax.COMMENT:
                return line[:i]
        return line


    #
    def traverse(self, o):
        if isinstance(o, (list, tuple)):
            for value in o:
                for subvalue in self.traverse(value):
                    yield subvalue
        else:
            yield o


    #
    def bin(self, s):
        return str(s) if s <= 1 else bin(s >> 1) + str(s & 1)


    #
    def bitlen(self, int):
        length = 0
        while int:
            int >>= 1
            length += 1
        return length


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print "please specify at least one assembly file."
    else:
        asm = Assembler(sys.argv[1:])
