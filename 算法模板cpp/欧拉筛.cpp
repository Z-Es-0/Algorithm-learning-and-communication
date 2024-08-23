vector<int >prime;
bool is_prime[N];//范围
void eulersiece(int n){//范围
    memset(is_prime,1,sizeof is_prime);
    for (int i = 2; i < n+1; ++i) {
        if (is_prime[i]){
            prime.push_back(i);
        }
        for (int j : prime) {
            if (i*j>n){
                break;
            }
            is_prime[i*j]= false;
            if (i%j==0){
                break;
            }
        }
    }
}