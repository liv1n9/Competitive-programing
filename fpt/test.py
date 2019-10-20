d = ['v', 'd', 'f']
s = 'acbaabc'
print(''.join(map(lambda x: d[ord(x)-97], s)))