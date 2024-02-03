// ques3Kernel.cl
__kernel void ques3(__global int *A)
{
    // Get the index of the current work item
    int i = get_global_id(0);
    
    // Do the operation
    int temp=A[2*i];
    A[2*i]=A[2*i+1];
    A[2*i+1]=temp;
    temp=0;
}