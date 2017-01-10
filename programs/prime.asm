# Determines if a user-entered number is prime
#
# def isPrime(num):
#   p = true
#   for (i = 2; i < num/2; i++):
#       if n % i == 0:
#           p = false
#           break
#   return p


iprompt
invoke .isprime

# param 0 -> number checked to be prime (n)
# local 1 -> iterator (i)
# local 2 -> isPrime flag (p)
define .isprime 1 2 int int byte
    ipush 2 istore 1
    bpush Y bstore 2

    label .loop
        # if n/i == 0 -> p=0, end loop
        iload 0
        iload 1
        imod
        ipush 0
        ifequal .notprime

        # i = i + 1
        iload 1
        ipush 1
        iadd
        istore 1

        # loop: i < (n/2)
        iload 1
        iload 0
        ipush 2
        idiv
        ifgreaterequal .end
        goto .loop

    label .notprime
        bpush N
        bstore 2

    label .end
        bload 2
        bprint
return
