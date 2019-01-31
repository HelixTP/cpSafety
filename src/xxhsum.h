/*
 * xxshum.h
 *
 *  Created on: 11 févr. 2018
 *      Author: lad
 */

#ifndef XXSHUM_H_
#define XXSHUM_H_

#endif /* XXSHUM_H_ */

typedef enum { algo_xxh32, algo_xxh64 } algoType;
typedef enum { big_endian, little_endian} endianess;

/*static int BMK_hashFiles(const char** fnList, int fnTotal,
                         algoType hashType, endianess displayEndianess);
*/

 int BMK_hash(const char* fileName,
                    const algoType hashType,
                    const endianess displayEndianess);
