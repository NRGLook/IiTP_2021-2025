#include <iostream>

using namespace std;

/** Header structure for linear buffer. */
typedef struct _LinearBuffer {


	uint8_t* mem;       /*!< Pointer to buffer memory. */
	uint32_t totalSize; /*!< Total size in bytes. */
	uint32_t offset;    /*!< Offset. */
} LinearBuffer;

/* non-aligned allocation from linear buffer. */
void* linearBufferAlloc(LinearBuffer* buf, uint32_t size) {


	if (!buf || !size)
		return NULL;


	uint32_t newOffset = buf->offset + size;
	if (newOffset <= buf->totalSize) {
		void* ptr = buf->mem + buf->offset;
		buf->offset = newOffset;
		return ptr;
	}
	return NULL; /* out of memory */
}

int main() {
	return 0;
}