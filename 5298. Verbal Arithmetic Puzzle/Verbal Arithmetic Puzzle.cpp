class Solution {
public:
    // check if the first digit is zero
    bool check0(map<char,int>& M){
        int sum =0;
        for(string s:words){
            if(M[s[0]]==0)
                return false;
        }
        if(M[result[0]]==0)
            return false;
        return true;
    }
    //generate all permutaion of digits recursively
    void generate(set<int>& used,int num, vector<int>& seq, vector<vector<int>>& res){
        if(num==0){
            res.push_back(seq);
            return;
        }
        for(int i=0;i<10;i++){
            if(used.count(i)==0){
                used.insert(i);
                seq.push_back(i);
                generate(used,num-1,seq,res);
                seq.pop_back();
                used.erase(i);
            }
        }
    }
    // test equality permutaion from the least significant bit.
    bool recursion(set<int>& used,map<char,int>& M,int d,int carry){
        if(d==rlen)
             return carry==0&&check0(M);
        set<char> addchars;
        for(string& s:words){
            int idx= s.length()-d-1;
            if(idx>=0&&M.count(s[idx])==0)
                addchars.insert(s[idx]);
        }
        int idx= result.length()-d-1;
        if(idx>=0&&M.count(result[idx])==0)
            addchars.insert(result[idx]);

        vector<int> seq;
        vector<vector<int>> res;
        generate(used,addchars.size(),seq,res);

        cout<<endl;
        for(vector<int>& S:res){
            int ind=0;
            for(char c:addchars){
                int digit=S[ind];
                M[c]= digit;
                used.insert(digit);
                ind++;
            }
            int sum =carry;
            for(string& s:words){
                int idx=s.length()-d-1;
                if(idx>=0)
                    sum+=M[s[idx]];
            }
            if(sum%10==M[result[rlen-d-1]]){
                if(rec(used,M,d+1,sum/10)) return true;
            }
            ind=0;
            for(char c:addchars){
                int digit=S[ind];
                M.erase(c);
                used.erase(digit);
                ind++;
            }

        }
        return false;

    }
    vector<string> words;
    string result;
    int rlen;
    bool isSolvable(vector<string>& words, string result) {
        this->words=words;
        this->result=result;
        rlen = result.length();
        int charnum=0;
        map<char,int> M;
        set<int> used;
        return recursion(used,M,0,0);


    }
};
