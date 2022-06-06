#include "header.h"
#include<stdio.h>
#include <stdlib.h>
#include <limits.h>

// ANY STATIC FUNCTIONS ARE UP HERE

static void dfs_for_first_question (int x , int ppl[] , int n , const connection_t graph[n][n])
{

    ppl[x] = 1;
    for(int u = x ; u < n ; u++)
    {

        for(int v = 0 ; v < n ; v++)
        {

            if (graph[u][v].distance != __INT_MAX__ && ppl[v]!= 1) // checking the condition
            {
            	dfs_for_first_question(v , ppl , n , graph); //using the same function again (recurrsion)
            }

        }

    }

}

static int check(int ppl[] , int n)
{

    for (int a = 0 ; a < n ; a++)
    {

        if (ppl[a] != 1)
        {
            return 0;  //if this if condion satisfies, this will go out of the loop
        }

        ppl[a] = 0;

    }

    return 1;

}

static void dfs_for_second_question (int x , int ppl[] , int n , const connection_t graph[n][n] , int dest , int num , int *sl)
{

    ppl[x] = 1;
    if (x == dest)
    {
        
        int f = 0; // f is initially set to 1
        for (int u  = 0 ; u < n ; u++)
        {

            if (ppl[u] == 1)
            {
                f++; //flag is incremented by 1
            }

        }
        if (f <= num+1)
        {
            *sl = 1;
        }
    }

    for(int u = x ; u < n ; u++)
    {

        for(int v = 0 ; v < n ; v++)
        {

            if (graph[u][v].distance != __INT_MAX__ && ppl[v]!= 1)
            {
               dfs_for_second_question(v , ppl , n , graph , dest , num , sl);  //recurrsion
            }

        }

    }

}




static void dfs_for_third_question (int x , int ppl[] , int n , const connection_t matrix[n][n] , int s , int *sl)
{

	ppl[x] = 1;
    	for(int u = x ; u < n ; u++)
    	{

        	for(int v = 0 ; v < n ; v++)
        	{

           		if (matrix[u][v].distance != __INT_MAX__ && v == s)
            	{
                		*sl = 1; // if condition is true sl will be 1
            	}

            	if (matrix[u][v].distance != __INT_MAX__ && ppl[v]!= 1)
            	{
                		dfs_for_third_question(v , ppl , n , matrix , s , sl); // recurrsion happens if the condition is true
           		} 

        	}

    	}

}





static void swap(airport_t *a, airport_t *b)
{

	airport_t t = *a;  // a is stored in temperoary variable t
    	*a = *b; // a is changed to b
    	*b = t; // b is changed to t which is a

}


static int dividing(airport_t arr[], int start, int end,int (*predicate_func)(const airport_t *, const airport_t *))
{
	airport_t pivot = arr[end];
	int u;
    	int indp = start;

    	for(u = start; u < end; u++)
    	{

        	if(predicate_func(&arr[u] , &pivot))
        	{
            	swap(&arr[u], &arr[indp]);
            	indp++; //if the condition is true indp is incremented
        	}

    	}

    	swap(&arr[end], &arr[indp]);
    	return indp;

}




static void quicksort(airport_t arr[], int start, int end,int (*predicate_func)(const airport_t *, const airport_t *) )
{

    if(start < end)
    {
        int qIndex = dividing(arr, start, end,predicate_func);  //using the dividing function which is defined before
        quicksort(arr, start, qIndex-1,predicate_func);  // recurrsion
        quicksort(arr, qIndex+1, end,predicate_func); // recurrsion
    }

}




static void shifttable(const char p[],int t[])
{

    int u,v,m=0;

    for(int x = 0 ; p[x] != '\0';x++)
    {

        m++;

    }

    for(u=0;u<500;u++)
    {

        t[u]=m;

    }

    for(v=0;v<m-1;v++)
    {

        t[p[v]-'0']=m-1-v;

    }

}




static int lent(airport_t airport1,airport_t airport2)
{
    int s=0;
    while(airport1.airport_name[s]!='\0' && airport2.airport_name[s]!='\0' && airport1.airport_name[s] == airport2.airport_name[s])
    {
        s++;
    }
    return s;
}




static int horspool(const char src[],const char p[],int t[])
{
    int u,k,m=0;
    int n=0;
    for(int x = 0 ; p[x] != '\0';x++)
    {

        m++;

    }

    for(int x = 0 ; src[x] != '\0';x++)
    {

        n++;

    }

    u=m-1;

    while(u<n)
    {

        k=0;
        while((k<m)&&(p[m-1-k]==src[u-k]))
        {
            k++;
        }

        if(k==m)
        {
            return(u-m+1);
        }

        else
        {
            u+= t[src[u]-'0'];
        }

    }
    return -1;
}


static int minimum_key_for_q9(int A,int key[], int min_sp_tree_set[])
{

    int minimum = INT_MAX, minimum_index;
 
    for (int q= 0; q < A; q++)
    {

        if (min_sp_tree_set[q] == 0 && key[q] < minimum)
        {
            minimum = key[q], minimum_index = q;
        }

    }

    return minimum_index;

}

static void prt_mst_for_q9(int V,int parent[], const connection_t graph[V][V],pair_t edges[V - 1])
{
    for (int i = 1; i < V; i++)
    {    

        edges[i-1].first = parent[i];
        edges[i-1].second = i;

    }
}

static int minimum_time_for_q9(int n,pair_t edges[],const connection_t graph[n][n],int parent[])
{

    int res = 0;

    for(int i=0;i<n-1;i++)
    {

        res = res + graph[edges[i].first][edges[i].second].time;

    }

    return res;

}
 


static void swap2(int *a,int *b)
{
    int temp=*a; // a is stored in temperoary variable temp
    *a=*b; // a is changed to b
    *b=temp; // b is changed to temp which is a
}

static void parr(int a[], int k,int graph[k][k],int* cost,int min_arr[])
{

    int min=0;
    a[k-1]=a[0];
    for (int u = 0; u < k-1; u++)
    {

        if(graph[a[u]][a[u+1]]!=INT_MAX)
        {
            min+=graph[a[u]][a[u+1]];
        }
        if(graph[a[u]][a[u+1]]==INT_MAX)
        {
            min=INT_MAX;
            u=k-1;
        }

    }
    
    if(*cost>min)
    {
        *cost=min;
       for(int i=0;i<k;i++)
       {
           min_arr[i]=a[i];
       }
    }
   
}
 

static void heap_perm(int a[], int size, int n,int k,int graph[][k],int* cost,int min_arr[n])
{

    if (size == 1) 
    {
        parr(a, k,graph,cost,min_arr);
        return;
    }
 
    for (int i = 0; i < size; i++) 
    {

        heap_perm(a, size - 1, n,k,graph,cost,min_arr);

        if (size % 2 == 1)
        {
            swap2(&a[0], &a[size - 1]);
        }

        else
        {
            swap2(&a[i], &a[size - 1]);
        }

    }
}

static void Dijkstra(int n,const connection_t Graph[n][n], int start,int *hash) 
{
    int visited[n], count, mindistance, nextnode, i, j;
    int cost[n][n], distance[n], pred[n];
    

    for (i = 0; i < n; i++)

        for (j = 0; j < n; j++)

        if (Graph[i][j].time == 0)
        {
            cost[i][j] = INT_MAX;
        }
        else
        {
            cost[i][j] = Graph[i][j].time;
        }

    for (i = 0; i < n; i++) 
    {

        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;

    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INT_MAX;

        for (i = 0; i < n; i++)
        if (distance[i] < mindistance && !visited[i]) {
            mindistance = distance[i];
            nextnode = i;
        }

        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
        if (!visited[i])
            if (mindistance + cost[nextnode][i] < distance[i]) {
            distance[i] = mindistance + cost[nextnode][i];
            pred[i] = nextnode;
            }
        count++;
    }

    for (i = 0; i < n; i++)
        if (i != start) {
        hash[i]  = distance[i];
        }
}


// YOUR SOLUTIONS BELOW

int q1(int n, const connection_t connections[n][n])
{

	int sl = 1;    
	int ppl[100000];

	for(int i = 0 ; i < n ; i++)
    	{
      	ppl[i] = 0;
      }

      for (int i = 0 ; i < n ; i++)
    	{
       	dfs_for_first_question(i , ppl , n , connections);
       	sl = sl & check(ppl , n);
    	}

    	return sl;

}

int q2(const airport_t *src, const airport_t *dest, int n, int k,const connection_t connections[n][n])
{

	int vd = dest->num_id;
    	int vs = src->num_id;
    	int ppl[100000];
    	int sl = 0;

    	for(int u = 0 ; u < n ; u++)
    	{
    	    ppl[u] = 0;
    	}

	dfs_for_second_question(vs , ppl , n , connections , vd , k , &sl); // This function is defined on the top

    	if(sl == 1)
    	{
       	 return 1; // returns 1
    	}

    	else
    	{
       	 return 0;  // returns 0
    	}

}

int q3(const airport_t *src, int n, const connection_t connections[n][n])
{

	int ppl[100000];
    	int s = src->num_id;
    	int sl = 0;

    	for(int i = 0 ; i < n ; i++)
    	{

       	 ppl[i] = 0; //initially it is equated to 0

   	}

    	dfs_for_third_question(s , ppl , n , connections, s , &sl);

    	return sl; // this returns sl

}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *),airport_t airport_list[n])
{
    quicksort(airport_list,0,n-1,predicate_func);
}

pair_t q5(int n, airport_t airports[n])
{
    pair_t sl = {-1, -1};
    int maxi = 0;
    int a;
    for(int u=0; u<n; u++)
    {
        for(int v = u+1; v<n; v++)
        {
            a = lent(airports[u],airports[v]);
            if(maxi < a)  //checking the condition
            {
                maxi = a;
                sl.first = airports[u].num_id;
                sl.second = airports[v].num_id;
            }
        }
    }
    return sl;  //returning sl

}

int q6(int n, int amount, const int entry_fee[n])
{

        int cen;
        int s=0, e=n-1;  //initialising s to 0
        while(s <= e) 
        {

            cen = s + (e-s)/2; 


            if(entry_fee[cen] == amount)
            {

                return cen+1;

            } 
            else if(entry_fee[cen] < amount)
            {
                s = cen+1;
            } 
            else
            { 
                e = cen-1;
            }
        }

        return s;  //returning s
}

void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{

    for(int u = 0; u<n ;u++)
    {

        int t[500] = {0};
        shifttable(pat,t);
        if(horspool(airports[u].airport_name,pat,t)>=0)  //horspool function defined before
        {
            contains[u] = 1;  //if the condition satifies
        }

    }

}

int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{

    int u;
    int v;
    int min_arr[n];
    int a[n];
    int graph[n][n];  //initialising the graph
	for(u=0;u<n-1;u++)
	{

		trip_order[u]=-1;

	}

    for(u=0;u<n;u++)
    {

        for(v=0;v<n;v++)
        {

            graph[u][v]= connections[u][v].distance;

        }

    }

    int k;
    int cost=INT_MAX;

    for(u=0;u<n;u++)
    {

        int c=0;
        for(int v=0;v<n;v++)
        {

            if(v!=u)
            {
            
            a[c++]=v;
            }
            
        }
        
        heap_perm(a, n-1, n-1,n,graph,&cost,min_arr);  //function defined before
        
    }

    if(cost==INT_MAX)
    {
        return -1;
    }

    else
    {
        for(int u=0;u<n-1;u++)
        {

            trip_order[u]=min_arr[u];

        }
        return cost;
    }

    return 0;

}

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    int u;
    int c;
    int key[n];
    int parent[n];
    int mstSet[n];

    for (u = 1; u < n; u++)
    {

        key[u] = INT_MAX, mstSet[u] = 0;
    
    }
 

    key[0] = 0;
    parent[0] = -1;
 
    for (int c = 0; c < n - 1; c++) {

        int w = minimum_key_for_q9(n,key, mstSet);
 
        mstSet[w] = 1;
 
        for (int v = 0; v < n; v++)
        {
 
            if (connections[w][v].time && mstSet[v] == 0 && connections[w][v].time < key[v])
            {

                parent[v] = w, key[v] = connections[w][v].time;

            }
        
        }
    }
 
    prt_mst_for_q9(n,parent, connections ,edges);

    return minimum_time_for_q9(n,edges,connections,parent);

}


void q10(int n, int k, const airport_t *src, const connection_t connections[n][n], const int destinations[k],int costs[k])
{

    int u=0; // variable u is initialised
    int hash[n];
    Dijkstra(n,connections,src->num_id,hash);
    while(u!= k)
    {

        costs[u] = hash[destinations[u]];
        u++; // u is incremented by 1

    }

}

// END