// Jinhao Chen
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include "MemoryManager.h"

using namespace std;


ostream & operator<<(ostream & out, const MemoryManager &M)
{
	blocknode *tmp = M.firstBlock;
	assert(tmp);
	while (tmp)
	{
		out << "[" << tmp->bsize << ",";
		if (tmp->free)
			out << "free] ";
		else
			out << "allocated] ";
		if (tmp->next)
			out << " -> ";
		tmp = tmp->next;
	}
	return out;
}

MemoryManager::MemoryManager(unsigned int memtotal) : memsize(memtotal)
{
	baseptr = new unsigned char[memsize];
	firstBlock = new blocknode(memsize, baseptr);
}

blocknode *MemoryManager::getFirstPtr()
{
	return firstBlock;
}

unsigned char * MemoryManager::malloc(unsigned int request)
// Finds the first block in the list whose size is >= request
// If the block's size is strictly greater than request
// the block is split, with the newly create block being free. 
// It then changes the original block's free status to false
{
	blocknode *current = getFirstPtr();
	while (!(current->free) || request > current->bsize)
	{
		current = current->next;
	}
	if (current->bsize == request && current->free == true)
		current->free = false;

	if (current->bsize > request && current->free == true)
	{

		splitBlock(current, request);
		current->free = false;
	}

	return current->bptr;
}

void MemoryManager::splitBlock(blocknode *p, unsigned int chunksize)
// Utility function. Inserts a block after that represented by p
// changing p's blocksize to chunksize; the new successor node 
// will have blocksize the original blocksize of p minus chunksize and 
// will represent a free block.  
// Preconditions: p represents a free block with block size > chunksize
// and the modified target of p will still be free.
{
	blocknode *j = new blocknode(p->bsize, p->bptr + chunksize);
	if (j->next == NULL){

		int temp = p->bsize;
		p->bsize = chunksize;
		p->next = j;
		j->prev = p;
		j->bsize = temp - chunksize;

		j->free = true;

	}
	else{
		int temp = p->bsize;
		j->next = p->next;
		p->next->prev = j;
		p->next = j;
		j->next = p;
		p->bsize = chunksize;
		j->bsize = temp - chunksize;
		j->free = true;

	}
	return;


}

void MemoryManager::free(unsigned char *blockptr)
// makes the block represented by the blocknode free
// and merges with successor, if it is free; also 
// merges with the predecessor, if it is free
{
	blocknode *i = firstBlock;
	while (i->bptr != blockptr)
		i = i->next;
	i->free = true;
	if (i->next->free == true && i->next)
	{
		mergeForward(i);
	}
	if (i->prev && i->prev->free)
		mergeForward(i->prev);
}

void MemoryManager::mergeForward(blocknode *p)
// merges two consecutive free blocks
// using a pointer to the first blocknode;
// following blocknode is deleted
{

	p->bsize = p->bsize + p->next->bsize;
	p->next = p->next->next;
}

