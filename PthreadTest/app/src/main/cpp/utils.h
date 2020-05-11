//
// Created by huihui on 2019/8/19.
//

#ifndef QLAUNCHER_UTILS_H
#define QLAUNCHER_UTILS_H

#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }



#endif //QLAUNCHER_UTILS_H
