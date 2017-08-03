#ifndef JEMALLOC_INTERNAL_TESTING_H
#define JEMALLOC_INTERNAL_TESTING_H

extern int	testing_malloc_fail;

int testing_malloc_fail_get(tsdn_t *tsdn);
int testing_malloc_fail_set(tsdn_t *tsdn, int code);
int testing_malloc_fail_get_and_clear(tsdn_t *tsdn);

#endif /* JEMALLOC_INTERNAL_TESTING_H */
