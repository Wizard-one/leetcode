
// #位运算 检查是否为二次幂
bool isPowerOfTwo(int n){
	return n>0 && (n & n-1)==0;
}