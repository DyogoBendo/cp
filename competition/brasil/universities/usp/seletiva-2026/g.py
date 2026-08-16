from math import sqrt

op = ["+", "-", "*", "/"]

def fat(x):                
    assert(isinstance(x, int) or x.is_integer())
    x = int(x)
    ans = 1
    for i in range(1, x+1):
        ans *= i
    return ans

ans = {}

def get_val(values, ops: list, open: list = [], close:list = []):
    if(isinstance(values, int) or isinstance(values, float)):
        return (values, str(values))            
        
    if(len(ops) == len(values) - 1 and len(open) < len(values)):        
        for i in range(2):
            open.append(i)
            for j in range(2):                
                close.append(j)
                get_val(values, ops, open, close)     
                close.pop()
            open.pop()
        return
    elif(len(ops) == len(values) - 1 and len(open) == len(values)):            
        s = ""
        if(open[0] == 1):
            s += "("
        s += str(values[0])
        if(close[0] == 1):
            s += ")"
        for i in range(len(ops)):
            s += ops[i]
            if(open[i+1] == 1):
                s += "("
            s += str(values[i+1])
            
            if(close[i+1] == 1):
                s += ")"
                                    
        try:        
            x = eval(s)
            if(isinstance(x, float) and x.is_integer()):
                x = int(x)
            if(isinstance(x, int)):
                if(ans.get(x) != None):
                    if(len(s) < len(ans[x])):
                        ans[x] = s
                else:
                    ans[x] = s
        except:
            pass
        return
        
    for o in op:
        ops.append(o)
        for i in range(2):
            open.append(i)
            for j in range(2):                
                close.append(j)
                get_val(values, ops, open, close)     
                close.pop()
            open.pop()
        ops.pop()

print(eval("44 / 4 * sqrt(4)"))
print(eval("(4 + 4)**sqrt(4) - 4"))
print(eval("4 - 4/4 + fat(4.0)"))

val = [("fat(4)", 1), (4, 1), (44, 2), (444, 3), (4444, 4), (.4, 1), (.44, 2), (.444, 3), (.4444, 4), (4.4, 2), (4.44, 3), (4.444, 4), (44.4, 3), (44.44, 4), (444.4, 4),
       ("4**4", 2), ("sqrt(4)", 1), ("sqrt(4**4)", 2), ("4**(sqrt(4))", 2)]

for (a1, b1) in val:
    if(b1 == 4):
        get_val((a1), [])
        continue
    for (a2, b2) in val:
        if(b1 + b2 == 4):
            get_val((a1, a2), [])
            continue        
        for(a3, b3) in val:
            if(b1 + b2 + b3 == 4):
                get_val((a1, a2, a3), [])
                continue
            for(a4, b4) in val:
                if(b1 + b2 + b3 + b4 == 4):
                    get_val((a1, a2, a3, a4), [])


print("{")
for i in range(1, 71):
    print(f'"{ans[i]},"')    
print("}")