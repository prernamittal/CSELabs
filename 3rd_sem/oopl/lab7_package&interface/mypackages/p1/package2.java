package mypackages.p1;
public class package2 
{
    public int max(int n1, int n2,int n3)
    {
        return ((n1>n2)?(n1>n3?n1:n3):(n2>n3?n2:n3));
    }
    public float max(float n1, float n2,float n3)
    {
        return ((n1>n2)?(n1>n3?n1:n3):(n2>n3?n2:n3));
    }
    public int max(int a[])
    {
        int max=0;
        for(int i : a)
        {
            if(i > max)
            {
                max=i;
            }
        }
            return max;
    }
    public int max(int a[][])
    {
        int max=0;
	    for(int b[] : a)
	    {
	       for(int i : b)
	       {
	          if(i > max)
	          {
                max = i;
	          }
	       }
	    }
	    return max;
	}
}
