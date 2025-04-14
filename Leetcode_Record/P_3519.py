class Solution:    
    
    def countNumbers(self, l: str, r: str, b: int) -> int:
        mod = 1000000007
        def trans_base(v:int,b:int) -> list[int]:
            out = []
            while v>0:
                out.append(v%b)
                v//=b
            if len(out)==0:
                return [0]
            return out[::-1]

        def cntndec(v,b):
            dp = [0]*b
            maxdp = [0]*b
            dp[v[-1]] = 1
            maxdp[b-1]=1
            n = len(v)
            for i in  reversed(range(n)):
                tmp = 0
                tmpmax = 0
                for j in reversed(range(b)):
                    tmpmax = (tmpmax+ maxdp[j])%mod
                    tmp = (tmp+dp[j])%mod
                    if j<v[i]:
                        dp[j]=tmpmax
                    elif j==v[i]:
                        dp[j] = tmp
                    else:
                        dp[j]=0
                    maxdp[j] = tmpmax
            out = 0
            for i in range(b):
                out = (out+dp[i])%mod
            return out
        l = int(l)
        r= int(r)
        r = trans_base(r,b)
        out = cntndec(r,b)
        if l>0:
            tmp = cntndec(trans_base(l-1,b),b)
            out = (out-tmp+mod)%mod
        return out
    
        
    