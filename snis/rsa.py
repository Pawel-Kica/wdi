def euler(n:int):
    primeFactors = []
    k = 2
    result = n

    while n != 1:
        while n % k == 0:
            n //= k
            primeFactors.append(k) if k not in primeFactors else None
        k += 1
    
    for primeFactor in primeFactors:
        result *=(1-1/primeFactor)

    return result 

def encryptRSA(n:int, public_key:int, msg:int):
    cipher = (pow(msg,public_key)) % n
    return cipher

def decryptRSA(private_key:int, public_key:int, fi_n:int, cipher:int):
    e = pow(public_key,-1,fi_n)
    msg = (pow(cipher,e)) % private_key
    return msg


if __name__ == "__main__":
    private_key = 17 * 23
    public_key = 3

    fi_n = int(euler(private_key))
    msg = 123

    print(f"message: {msg}")

    cipher = encryptRSA(private_key, public_key, msg)
    print(f"cipher {cipher}")

    encrypted_msg = decryptRSA(private_key, public_key, fi_n, cipher)
    print(f"encrypted_msg {encrypted_msg}")