s = input()
K = int(input())
 
substrings = set()
 
for i in range(len(s)):
    for j in range(i+1, min(len(s)+1, i+K+1)):
        substrings.add(s[i:j])
 
substrings_list = sorted(list(substrings))
print(substrings_list[K-1])
