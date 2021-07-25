from hashlib import sha256
import time
scan = input("write anything ")
dr = '00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF'
rndm = 1
t1 = time.time()
while (rndm):
   rndmn = str(rndm)
   new = sha256(str.encode(scan + rndmn))
   if (int(new.hexdigest(),16) < int(dr,16)):
      break
   rndm += 1
t2 = time.time()
print('The value for nonce is ',rndm)
print ('The time taken is ',t2 - t1)
