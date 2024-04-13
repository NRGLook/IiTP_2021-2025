using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153504_Tihanenok_Lab2.Interfaces;
using _153504_Tihanenok_Lab2.Exceptions;

namespace _153504_Tihanenok_Lab2.Collections
{
    public class MyCustomCollection<T> : ICustomCollection<T>, IEnumerable<T>
    {
        private Node<T>? current, head, tail;
        private int count = 0;

        public MyCustomCollection() { }

        public T this[int index]
        {
            get
            {
                if(index < 0 || index >= count) 
                    throw new IndexOutOfRangeException("index out of range");
                var tmpCurrent = head;
                for (int i = 0; i < index; i++)
                {
                    tmpCurrent = tmpCurrent.next;
                }
                return tmpCurrent.value;
            }
            set
            {
                if (index < 0 || index >= count) 
                    throw new IndexOutOfRangeException("index out of range");
                var tmpCurrent = head;
                for (int i = 0; i < index; i++)
                {
                    tmpCurrent = tmpCurrent.next;
                }
                tmpCurrent.value = value;
            }
        }

        public int Count
        {
            get => count;
        }

        public T? Current()
        {
            return current.value;
        }

        public void Next()
        {
            if (current != null)
            {
                current = current.next;
            }
        }

        public T? RemoveCurrent()
        {
            var tmpCurrent = head;
            if(tmpCurrent == null) return default;
            if(current == head)
            {
                head = head.next;
                current = head;
                count--;
            }
            else
            {
                while (tmpCurrent.next != null && tmpCurrent.next != current)
                {
                    tmpCurrent = tmpCurrent.next;
                }
                this.current = tmpCurrent;
                if (tmpCurrent.next != null)
                {
                    tmpCurrent.next = tmpCurrent.next.next;
                    count--;
                }
            }
            return tmpCurrent.value;
        }

        public void Reset()
        {
            current = head;
        }

        public void Add(T? item)
        {
            if (item == null)
            {
                throw new ArgumentNullException(nameof(item));
            }
            //create new node
            Node<T> new_node = new Node<T>(item);
            if (count == 0)
            {
                current = head = tail = new_node;
            }
            else
            {
                tail.next = new_node;
                tail = tail.next;
            }
            count++;
        }

        public void Remove(T item)
        {
            var curr = head;
            //null base case
            if (curr == null) throw new InvalidOperationException("Sequence contains no elements");

            if(curr.value.Equals(item))
            {
                head = head.next;
                if(count == 1)
                {
                    tail = null;
                }
                count--;
            }
            else
            {
                while (curr.next != null && !curr.next.value.Equals(item))
                {
                    curr = curr.next;
                }
                if (curr.next != null && curr.next.value.Equals(item))
                {
                    if (curr.next == tail)
                    {
                        tail = curr;
                    }
                    curr.next = curr.next.next;
                    count--;
                }
                else throw new ValueNotFoundException("There is no item with such value");
            }
        }

        public IEnumerator<T> GetEnumerator() => new MyCustomCollectionEnumerator<T>(head);

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
    }
}
