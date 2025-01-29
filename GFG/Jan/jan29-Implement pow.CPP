 double power(double b, int e) {
        // code here
        if(b<0){
            if(e<0){
                e = abs(e);
                if(e%2==0){
                    return 1/pow(abs(b), e);
                }
                else{
                    return -1/pow(abs(b), e);
                }
            }
            else{
                if(e%2==0)
                return pow(abs(b), e);
                else
                return -1*pow(abs(b), e);
            }
        }
        else{
            if(e<0){
                return 1/pow(b, abs(e));
            }
            else{
                return pow(b, e);
            }
        }
    }