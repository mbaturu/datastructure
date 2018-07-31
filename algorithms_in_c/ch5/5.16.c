void traverse(Link h,void (*visit)(Link)){
	QUEUEinit(max);QUEUEput(h);
	while(!QUEUEempty()){
		(*visit)(h=QUEUEget());
		if(h->l!=NULL)QUEUEput(h->l);
		if(h->r!=NULL)QUEUEput(h->r);
	}
}
