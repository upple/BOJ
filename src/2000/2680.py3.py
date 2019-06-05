n=int(input())
alpha_code = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:'
NEW_INPUT = 9
NUMERIC = 1
ALPHA = 2
BYTE_CODE = 4
KANJI = 8
TERMINATION = 0
while n:
    code = int(input(), 16)
    state = NEW_INPUT
    ans = ''
    p = 38*4
    ret_size = 0
    while p>0:
        if state == TERMINATION:
            break

        elif state == NEW_INPUT:
            p-=4
            state = code//(2**p)
            code%=2**p

        elif state == NUMERIC:
            p-=10
            size = code//(2**p)
            code%=2**p
            while size:
                if size == 1:
                    p-=4
                    data = code//(2**p)
                    code%=2**p
                    ret_size+=1
                    size-=1
                    ans+='%01d'%data
                elif size == 2:
                    p-=7
                    data = code//(2**p)
                    code%=2**p
                    ret_size+=2
                    size-=2
                    ans+='%02d'%data
                else:
                    p-=10
                    data = code//(2**p)
                    code%=2**p
                    ret_size+=3
                    size-=3
                    ans+='%03d'%data

            state = NEW_INPUT
        
        elif state == ALPHA:
            p-=9
            size = code//(2**p)
            code%=2**p
            
            while size:
                if size==1:
                    p-=6
                    data = code//(2**p)
                    code%=2**p
                    ret_size+=1
                    size-=1
                    ans+=alpha_code[data]

                else:
                    p-=11
                    data = code//(2**p)
                    code%=2**p
                    ret_size+=2
                    size-=2
                    data1 = alpha_code[data//45]
                    data2 = alpha_code[data%45]
                    ans+= data1+data2

            state = NEW_INPUT

        elif state == BYTE_CODE:
            p-=8
            size = code//(2**p)
            code%=2**p

            while size:
                p-=8
                size-=1
                data = code//(2**p)
                code%=2**p
                ret_size+=1
                if data>=0x20 and data<=0x7e:
                    ans+=chr(data)
                
                else:
                    ans+='\\'+'%02X'%(data)

            state = NEW_INPUT

        elif state == KANJI:
            p-=8
            size = code//(2**p)
            code%=2**p

            while size:
                p-=13
                size-=1
                data = code//(2**p)
                code%=2**p
                ret_size+=1
                ans+='#'+'%04X'%(data)

            state = NEW_INPUT
    print(ret_size, ans)
    n-=1