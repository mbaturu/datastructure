void traverse(int k,void (*visit)(int)){
	Link t;
	(*visit)(k);visited[k]=1;
	for(t=adj[k];t!=NULL;t=t->next){
		if(!visited[t->v])traverse(t->v,visit);
	}

}
