// ques1Kernel.cl
__kernel void ques1(__global int *A, __global int *B)
{
    // Get index of current work item
    int i = get_global_id(0);
    // Do the operation
    int a = 0, b = 1, n = A[i];
    while(n!=0){
        a += (n%8) * b;
        n/=8;
        b*=10;
    }
    B[i] = a;
}