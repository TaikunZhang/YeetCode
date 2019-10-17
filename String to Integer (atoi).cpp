class Solution {
public:
    int myAtoi(string str) {
       long num = 0;
       int i = 0;
       int sign = 0;
       bool num_exist = 0;
        while(str[i] == ' '){
            i++;
        }
        if(i == str.size()-1 && str.size() != 1){
            return 0;
        }
        else if(str[i] == '-'){
            sign = 1;
            i++;
        }
        else if(str[i] == '+'){
            sign = 2;
            i++;
        }
        
        for (i;i < str.size(); ++i){
            if(str[i] < 48 || str[i] >= 58){
                if(!num_exist){
                    return 0;
                }
                if(sign == 1)return -num;
                return num;
            }
            else{
                num_exist = 1;
                num = num * 10;
                num += int(str[i])-48;
                 if(num > INT_MAX){
                    if(sign == 1){
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
            }
        }
      if(sign == 1)return -num;
      return num;
    }
};