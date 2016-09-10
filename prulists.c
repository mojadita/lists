/* $Id: prulists.c,v 1.2 2005/08/18 09:18:39 luis Exp $
 * Author: Luis Colorado <Luis.Colorado@HispaLinux.ES>
 * Date: Mon Jul 18 17:53:02 CEST 2005
 *
 * Disclaimer:
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#define IN_PRULISTS_C

/* Standard include files */
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "lists.h"

/* constants */

/* types */
struct nodo {
		int     num;
		LNODE_T node;
};

LIST_DECLARE(lista_nodos);

/* prototypes */

/* variables */

struct nodo *add(int num) {
    struct nodo *n = malloc(sizeof *n);
    n->num = num;
    LIST_APPEND_ELEMENT(&lista_nodos, n, struct nodo, node);
    return n;
}

void list(){
    struct nodo *n;
    printf("size=%d: ", lista_nodos.l_size);
    LIST_FOREACH_ELEMENT(n, &lista_nodos, struct nodo, node) {
        printf("<%d>", n->num);
    }
    printf(";\n");
}

int main (int argc, char **argv)
{
    struct nodo *n;
    add(1); list();
    add(2); list();
    add(3); list();
    while(n = LIST_FIRST_ELEMENT(&lista_nodos, struct nodo, node)) {
        LIST_UNLINK_ELEMENT(&lista_nodos, n, struct nodo, node);
        list();
    }
    add(4); list();
    n = add(5); list();
    add(6); list();
    LIST_UNLINK_ELEMENT(&lista_nodos, n, struct nodo, node); list();
    while(n = LIST_LAST_ELEMENT(&lista_nodos, struct nodo, node)) {
        LIST_UNLINK_ELEMENT(&lista_nodos, n, struct nodo, node); list();
    }
} /* main */


/* $Id: prulists.c,v 1.2 2005/08/18 09:18:39 luis Exp $ */
