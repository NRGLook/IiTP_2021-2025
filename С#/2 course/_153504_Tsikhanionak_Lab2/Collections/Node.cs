using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Tihanenok_Lab2.Collections
{
    public class Node<T>
    {
        public Node() { }
        public Node(T value, Node<T>? next = null)
        {
            this.value = value;
            this.next = next;
        }

        public Node<T>? next;
        public T? value;
    }
}
