 # i n c l u d e   < s t d i o . h > 
 
 # d e f i n e   M A X _ K E Y W O R D _ S I Z E   1 2 8 
 # d e f i n e   M A X _ K E Y W O R D _ C O U N T   2 0 
 # d e f i n e   M A X _ M E S S E G E _ S I Z E   2 5 6 
 # d e f i n e   M A X _ M E S S E G E _ C O U N T   2 5 6 
 
 / /  �PQ��[u+  m�N�P~� ,  m�N�P{�  �PQ��[r�  O��Pu+  ��R8�O� . 
 i n t   i n p u t _ k e y w o r d s ( c h a r   k e y w o r d s [ M A X _ K E Y W O R D _ C O U N T ] [ M A X _ K E Y W O R D _ S I Z E ] )   { 
     / /  Rr  O�r�  �PQ��[UJ  NP~�v$  S�S�N  Q��P 
     i n t   k e y w o r d _ c o u n t   =   0 ; 
     p r i n t f ( 
             "_%c�   % d  ��x�r�  �PQ��[u+  m�N�z�b�Y8 .   (m�N��  N�dyY�d   !u+  m�N�z�b�Y8 ) \ n " , 
             M A X _ K E Y W O R D _ S I Z E ) ; 
     f o r   ( i n t   i   =   0 ;   i   <   M A X _ K E Y W O R D _ C O U N T ;   i + + )   { 
         p r i n t f ( " % d�c�  �PQ��[ :   " ,   i   +   1 ) ; 
         s c a n f _ s ( " % s " ,   k e y w o r d s [ i ] ,   M A X _ K E Y W O R D _ S I Z E ) ; 
 
         i f   ( k e y w o r d s [ i ] [ 0 ]   = =   ' ! ' )   { 
             k e y w o r d _ c o u n t   =   i ; 
             p r i n t f ( "�PQ��[  m�N�c^  W:�fV��jO� . \ n \ n " ) ; 
             b r e a k ; 
         } 
     } 
 
     p r i n t f ( "m�N�z��  �PQ��[~�  ��   % dO�  m��jO� . \ n " ,   k e y w o r d _ c o u n t ) ; 
     f o r   ( i n t   i   =   0 ;   i   <   k e y w o r d _ c o u n t ;   i + + )   { 
         p r i n t f ( " % s " ,   k e y w o r d s [ i ] ) ; 
         i f   ( i   <   k e y w o r d _ c o u n t   -   1 )   { 
             p r i n t f ( " ,   " ) ; 
         }   e l s e   { 
             p r i n t f ( " \ n " ) ; 
         } 
     } 
 
     r e t u r n   k e y w o r d _ c o u n t ; 
 } 
 
 i n t   m a i n ( )   { 
     / /  v�w�v$u+  S�S�N  xEQ� 
     c h a r * *   m e s s e g e s   =   ( c h a r * * )   m a l l o c   ( M A X _ M E S S E G E _ C O U N T   *   ( i n t ) s i z e o f ( c h a r * ) ) ; 
     f o r   ( i n t   i   =   0 ;   i   <   M A X _ M E S S E G E _ C O U N T ;   i + + ) 
     { 
         m e s s e g e s [ i ]   =   ( c h a r * )   m a l l o c   ( M A X _ M E S S E G E _ S I Z E   * ( i n t ) s i z e o f ( c h a r * ) ) ; 
     } 
     / /   c h a r   m e s s e g e s [ M A X _ M E S S E G E _ C O U N T ] [ M A X _ M E S S E G E _ S I Z E ] ; 
     / /  �PQ��[u+  S�S�N  xEQ� 
     c h a r * * *   k e y w o r d s   =   ( c h a r * * * )   m a l l o c   ( M A X _ M E S S E G E _ C O U N T *   ( i n t ) s i z e o f ( c h a r * * ) ) ; 
     f o r   ( i n t   i   =   0 ;   i   <   M A X _ M E S S E G E _ C O U N T ;   i + + ) 
     { 
         k e y w o r d s [ i ]   =   ( c h a r * * )   m a l l o c   ( M A X _ K E Y W O R D _ C O U N T * ( i n t ) s i z e o f ( c h a r * ) ) ; 
         f o r   ( i n t   j   =   0 ;   j   <   M A X _ K E Y W O R D _ C O U N T ;   j + + ) 
         { 
             k e y w o r d s [ i ] [ j ]   =   ( c h a r * )   m a l l o c   ( M A X _ K E Y W O R D _ S I Z E * ( i n t ) s i z e o f ( c h a r ) ) ; 
         } 
     } 
     c h a r   k e y w o r d s [ M A X _ M E S S E G E _ C O U N T ] [ M A X _ K E Y W O R D _ C O U N T ] [ M A X _ K E Y W O R D _ S I Z E ] ; 
 
     / /  v�b�v$r�  O��P ,  �PQ��[r�  O��Pu+  S�S�N  Q��P 
     i n t   m e s s e g e _ c o u n t   =   0 ; 
     i n t   k e y w o r d _ c o u n t   =   0 ; 
 
     / /  `%t6�  v�f%u+  S�S�N  Q��P 
     i n t   m e n u   =   0 ; 
 
     p r i n t f ( " * * * * * * * * * *x�`�  v�b�v$  y�]�bA * * * * * * * * * * \ n \ n " ) ; 
 
     w h i l e   ( 1 )   { 
         p r i n t f ( " - - - - - - - - -v�f%u+  `%t6z�b�Y8 - - - - - - - - - - \ n " ) ; 
         p r i n t f ( " 1 .  �PQ��[��  v�b�v$  y�]�z�bA \ n " ) ; 
         p r i n t f ( " 2 .  v�b�v$  QMN�z�bA \ n " ) ; 
         p r i n t f ( " 3 .  v�b�v$  r�y�]�z�bA \ n " ) ; 
         p r i n t f ( " 4 .  v�b�v$  fR�z�bA \ n " ) ; 
         p r i n t f ( " 5 .  ��N0z�bA \ n " ) ; 
         s c a n f _ s ( " % d " ,   & m e n u ) ; 
 
         i f   ( m e n u   = =   1 )   { 
             / /  �PQ��[u+  m�N�P~�  O��Pu+  Q��PO�  S�S��O� . 
             k e y w o r d _ c o u n t   =   i n p u t _ k e y w o r d s ( k e y w o r d s [ m e s s e g e _ c o u n t ] ) ; 
 
             / /   T O D O .  v�b�v$  y�]�z�~�  bAt�  w UJ 
         } 
 
         e l s e   i f   ( m e n u   = =   2 )   { 
             / /   T O D O .  v�b�v$  QMN�z�~�  bAt�  w UJ 
 	 	 } 
 
 	 	 e l s e   i f   ( m e n u   = =   3 )   { 
 	 	 	 / /   T O D O .  v�b�v$  r�y�]�z�~�  bAt�  w UJ 
 	 	 } 
 
 	 	 e l s e   i f   ( m e n u   = =   4 )   { 
 	 	 	 / /   T O D O .  v�b�v$  fR�z�~�  bAt�  w UJ 
 	 	 } 
 
 	 	 e l s e   i f   ( m e n u   = =   5 )   { 
 	 	 	 p r i n t f ( "jG��_
O�  ��N0���jO� . \ n " ) ; 
 	 	 	 b r e a k ; 
     } 
 }