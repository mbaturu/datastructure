void traverse(Link h,void (*visit)(Link)){
	STATCKinit(max);STAcKpush(h);
	while(!STACKempty()){
		(*visit)(h=STACKpop());
		if(h->r!=NULL)STACKpush(h->r);
		if(h->l!=NULL)STACKpush(h->l);
}
