// Validate IP Address

class Solution {
public:
    bool validIPV4(string ip) {
        if(count(ip.begin(), ip.end(), '.') > 3)
            return false;
        vector<string> tokens;
        stringstream check1(ip);
        
        string temp;
        
        while(getline(check1, temp, '.')) {
            tokens.push_back(temp);
            for(char c : temp)
                if(c < '0' || c > '9')
                    return false;
            
           if(temp.size() > 3)
               return false;
            
            if(temp.empty() || stoi(temp) > 255 || (temp[0] == '0' && (temp.size() > 1)))
                return false;
        }
        
        if(tokens.size() != 4)
            return false;
    
        return true;
    }
    
    bool validIPV6(string ip) {
        if(count(ip.begin(), ip.end(), ':') > 7)
            return false;
        vector<string> tokens;
        stringstream check1(ip);
        
        string temp;
        
        while(getline(check1, temp, ':')) {
            
            for(char c : temp)
                if(c == '-' || !((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <='F')))
                    return false;
            if(temp.size() > 4)
                return false;
            if(temp.empty() || ((temp[0] == '0' && temp.size() > 4)))
                return false;
            tokens.push_back(temp);
        }
        
        if(tokens.size() != 8)
            return false;
    
        return true;
    }
    
    string validIPAddress(string ip) {
        if(validIPV4(ip))
            return "IPv4";
        if(validIPV6(ip))
            return "IPv6";
        return "Neither";
    }
};