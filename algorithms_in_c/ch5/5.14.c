void traverse(Link h,void (*visit)(Link)){
	(*visit)(h);
	traverse(h->l,visit);
	traverse(h->r,visit);
}
