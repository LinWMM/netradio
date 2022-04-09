#ifndef MEDIALIB_H__
#define MEDIALIB_H__

struct mlib_listentry_st
{
	chnid_t chnid;
	char* desc;
};

int mlib_getchnlist(struct mlib_listentry_st **, int*);

int mlib_freechnlist(struct mlib_listentry_st *);

ssize_t mlib_readchn(chnid_t chnid, void* buf, size_t size);


#endif
