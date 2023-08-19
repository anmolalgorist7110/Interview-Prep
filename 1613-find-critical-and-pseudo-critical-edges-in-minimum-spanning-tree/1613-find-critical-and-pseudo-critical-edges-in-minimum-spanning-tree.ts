function findCriticalAndPseudoCriticalEdges(n: number, edges: number[][]): number[][] {
    let copyEdges=[...edges];
    
    let mst=findMst(n,copyEdges,[],[]);
    let critical:number[]=[];
    let pseudoCritical:number[]=[];
    
    for(let i =0;i<edges.length;i++)
        {
         
            let delMst=findMst(n,copyEdges,[],edges[i]);
            
            if(delMst!=mst){
                critical.push(i);
                continue;   
            }
            let forceMst=findMst(n,copyEdges,edges[i],[]);
            
            if(forceMst==mst)
                pseudoCritical.push(i);
    
        }
    return [critical,pseudoCritical];

};

function filterRow(rowNum:number, arr:number[][]): number[][]{
    let copy:number[][]=[];
    
    for(let i=0;i<arr.length;i++)
        if(i!=rowNum)
            copy.push(arr[i]);
    
    return copy;
    
    
}

function findMst(n:number, edges: number[][],forceEdge:number[],deleteEdge:number[]):  number {
    
   edges.sort((a,b)=>a[2]-b[2]);

   const parent= Array(n);
   const rank=Array(n).fill(0);
    
   for(let i=0;i<n;i++)
      parent[i]=i;
   
    

    
   let mst:number=0;
   let numEdges:number=0;
   
    
   if(forceEdge.length!=0)
       {
          let edge=forceEdge;
           let v1=edge[0];
           let v2=edge[1];
           let weight=edge[2];
           
           if(findParent(v1,parent)!=findParent(v2,parent))
               {
                   numEdges++;
                   mst+=weight;
                     
                   union(v1,v2,rank,parent);
                
               }
       }
    
    
   for(let i=0;i<edges.length;i++)
       { 
           
           
           
           let edge=edges[i];
           let v1=edge[0];
           let v2=edge[1];
           let weight=edge[2];
           
           if(deleteEdge.length!=0 && v1==deleteEdge[0] && v2==deleteEdge[1])
               continue;
           
           
           if(findParent(v1,parent)!=findParent(v2,parent))
               {
                   numEdges++;
                   mst+=weight;
                   union(v1,v2,rank,parent);
                  
               }
           
           if(numEdges==n-1)
               break;
          
       }
    
    return mst;
    
}

function findParent(vertex: number, parent: number[]): number{
    if(parent[vertex]==vertex)
        return vertex;
    
    return parent[vertex]=findParent(parent[vertex],parent);
    
    
}


function union(v1:number, v2:number, rank:number[], parent:number[] ): void {
    v1=findParent(v1,parent);
    v2=findParent(v2,parent);
    
    if(rank[v1]>rank[v2])
        {
            parent[v2]=v1;
        }
    else if(rank[v2]>rank[v1])
        parent[v1]=v2;
    else{
        parent[v2]=v1;
        rank[v1]++;
    }
}