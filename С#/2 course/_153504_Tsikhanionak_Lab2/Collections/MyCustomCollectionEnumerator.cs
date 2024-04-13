using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace _153504_Tihanenok_Lab2.Collections
{
    class MyCustomCollectionEnumerator<T> : IEnumerator<T>
    {
        Node<T>? current = null, head = null;
        public MyCustomCollectionEnumerator(Node<T>? head)
        {
            this.head = head;
        }

        public object Current
        {
            get
            {
                if (current == null)
                    throw new NullReferenceException();
                return current.value;
            }
        }
                                                                    
        T IEnumerator<T>.Current
        {
            get
            {
                if (current == null)
                    throw new NullReferenceException();
                return current.value;
            }
        }

        public void Dispose() { }

        public bool MoveNext()
        {
            if(current == null)
            {
                current = head;
                return true;
            }
            else if (current.next != null)
            {
                current = current.next;
                return true;
            }
            else
                return false;
        }
        public void Reset() => current = head;
    }   
}