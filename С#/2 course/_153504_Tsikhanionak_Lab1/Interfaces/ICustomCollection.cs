using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153504_Tsikhanionak_Lab1.Interfaces
{
    public interface ICustomCollection<T>
    {
        public T this[int index] { get;set; }

        public void Reset();

        public void Next();

        public T? Current();

        int Count { get; }

        public void Add(T item);
        
        public void Remove(T item);

        public T? RemoveCurrent();
    }
}
