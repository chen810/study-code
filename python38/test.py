import hashlib
msg = "73.25%"

for i in range(100000000):
    if i % 1000000 == 0:
        print("{0}==>{1}".format(i, msg))
    p = hashlib.md5()
    p.update(msg.encode(encoding= 'utf-8'))
    msg = p.hexdigest()

print(msg)
