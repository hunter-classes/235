
Node *merge(Node *a, Node *b){
  Node *ap;
  Node *bp;
  Node *newlist,*tmp;

  newlist = nullptr;
  ap = a;
  bp = b;
  while (ap!=nullptr && bp != nullptr){
    if (ap->getValue() < bp->getValue()){
      tmp = ap;
      ap = ap->getNext();
      tmp->setNext(newlist);
      newlist = tmp;
    } else{
      tmp = bp;
      bp = bp->getNext();
      tmp->setNext(newlist);
      newlist = tmp;
      }
  }

  /*  one of the two lists will need to be copied over */
  while (ap != nullptr){
    tmp = ap;
    ap = ap->getNext();
    tmp->setNext(newlist);
    newlist = tmp;
  }

  while (bp != nullptr){
    tmp = bp;
    bp = bp->getNext();
    tmp->setNext(newlist);
    newlist = tmp;
  }

  return reverse(newlist);
  
}
