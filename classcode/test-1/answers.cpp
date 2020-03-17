/* Test 1 sample solutions


 */


int length(Node *l){
  int count=0;
  if (head==nullptr){
    return 0;
  }
  Node *l  head;
  while (l!=nullptr){
    count++;;
    l=l->getNext();
  }
  return count;
}

Node *middle(Node *head){
  Node *tmp = head;
  int midpoint = length(head)/2;
  int i=0;
  if (midpoint <=0){
    return nullptr;
  }
  while (i<midpoint){
    tmp = tmp->getNext();
    i++;
  }
  return tmp;
}


Node *msort(Node *head){
  Node *lower, *tmp;
  Node *upper = middle(head);
  lower = head;
  tmp = head;
  while (tmp->getNext() != upper){
    tmp = tmp->getNext();
  }
  tmp->setNext(nullptr);
  return merge( msort(lower) , msort(upper));
}

Node *rotate(Node *head, int position){
  Node *tmp = head;
  Node *newhead;
  int i;
  int count = length(head);
  if (count < position){
    return head;
  }

  while (i < count){
    tmp = tmp->getNext();
    i++;
  }

  newhead = tmp->getNext();
  tmp->setNext(nullptr);

  tmp = newhead;
  while (tmp->getNext() != nullptr){
    tmp = tmp->getNext();
  }

  tmp->setNext(head);
  return newhead;
  
}

/*
  big O

  O(n) - you have to shift all the elements down - worst case linear
  O(n) - there can be any number of vowels at the start - linear search 
         - you could use c for the char count - I should have used
         - another variable name since c usually means constant
    O(1) - or O(k) or O(c) - constant - just fiddle pointers at the head
    O(lgn) binary search
    O(n) - removal would be O(1) but you have to find the element first
         - and you don't know if the pointer points to it or not
	 O(n) - must search through every element

*/

int main(int argc, char *argv[])
{
  
  return 0;
}
