// ques2Kernel.cl
__kernel void ques2(__global int *A, __global int *B)
{
    // Get the index of the current work item
    int i = get_global_id(0);
    
    // Do the operation
    int n = A[i];
    int pow=1,rem,binary=0;
    
    while (n!= 0) 
    {
        rem = n % 10;
        
        if (rem==0)
            binary=binary+1*pow;
        else
            binary=binary+0*pow;
        pow = pow * 10;
        n /= 10;
    }
    B[i]=binary;
}