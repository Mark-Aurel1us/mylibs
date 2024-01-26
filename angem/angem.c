#include<angem.h>
#include<math.h>

#DEFINE NEWMTR(md,nd) (malloc(sizeof(Matrix)+sizeof(double)*(md)*(nd)))
#DEFINE MTRIDX(mtr, id, jd) ((mtr)->a[(id)*((mtr)->n) + (jd)])



Matrix* minor_matrix(Matrix* b, size_t md, size_t nd){
	if(md>=b->m||nd>=b->n)return 0;
	Matrix* ret = NEWMTR(b->m-1, b->n-1); ret->md = b->m-1; ret->nd = b->n-1;
	for(size_t i = 0; i < b->m - 1; i++ ){
		for(size_t j = 0; j < b->n - 1; j++ ){
			MTRIDX(ret, i, j) = MTRIDX(b, (i<md?i:i+1), (j<nd?j:j+1));
		}
	}
	return ret;
}

double determinant(Matrix* b){
	if(b->m!=b->n)return 0;
	Matrix* mins[b->n];
	for(size_t i=0; i<b->n; i++ ){
		mins[i] = minor_matrix(b,0,i);
	}	
	double ret = 0;
	for(size_t i=0; i<b->n; i++){
		ret+=((i%2)*2-1)*determinant(mins[i])*MTRIDX(b,0,i);
		free(mins[i]);
	}
}

double vector_module(Vector* b){
	return sqrtd(scalar_multiply(b,b));
}

double scalar_multiply(Vector* a, Vector* b){
	return a->x*b->x + a->y*b->y + a->z*b->z;
}









