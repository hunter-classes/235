
Node *reverse(Node *l){
  Node *prev = nullptr;
  Node *curr = l;

  if (l==nullptr)
    return l;

  Node *next = cur->getNext();
  while (next != nullptr){
    curr->setNext(prev);
    prev = curr;
    curr = next;
    next = curr->getNext();
  }
  curr->setNext(prev);
  return curr;
}


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
