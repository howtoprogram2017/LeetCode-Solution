class Solution {
public:
    int minInsertions(string s) {
        int len =s.length();
        // M[i][j] is the table of minInsertions of substring indexed from i to j
        int M[500][500];
        memset(M,0,sizeof(M));
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                // the last character is able to match with all same character before it
                // or it is match with the inserted character
                int Min = 1+M[j][i-1];
                for(int k=j;k<i;k++)
                    if(s[i]==s[k])
                        Min=min(Min,M[k+1][i-1]+k-j);
                M[j][i]=Min;
            }
        }
        return M[0][len-1];
    }
};
