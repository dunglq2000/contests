def maj(x1,x2,x3):
    return (x1*x2+x1*x3+x2*x3) % 2
   
def P(state):
    next_state = []
    for i in range(1, len(state)):
        next_state.append(state[i])
    next_state.append((state[0]+state[1]+state[2]+state[5]) % 2)
    return next_state   
    
def Q(state):
    next_state = []
    for i in range(1, len(state)):
        next_state.append(state[i])
    next_state.append((state[0]+state[1]) % 2)
    return next_state
    
    
def R(state):
    next_state = []
    for i in range(1, len(state)):
        next_state.append(state[i])
    next_state.append((state[0]+state[3]) % 2)
    return next_state
    
def get_gamma(stateP, stateQ, stateR, gamma_len):
    gamma_bits = []
    for i in range(gamma_len):
        gamma_bits.append((maj(stateP[3],stateP[4],stateP[6])+maj(stateQ[5],stateQ[8],stateQ[12])) % 2)
        if stateR[4] == maj(stateR[2], stateR[3], stateR[4]):
            stateP = P(stateP)
        if stateR[2] == maj(stateR[2], stateR[3], stateR[4]):
            stateQ = Q(stateQ)
        stateR = R(stateR)
    return gamma_bits  
    
    
def get_gamma_from_password(password_bytes, n):
    key = [int(x) for x in bin(int.from_bytes(password_bytes, "big"))[2:].zfill(46)]
    print(key)
    stateP = key[0:19]
    stateQ = key[19:19+22]
    stateR = key[19+22:19+22+5]
    return get_gamma(stateP, stateQ, stateR, n)
