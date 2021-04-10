// arguments
#define CS_ARG_VIS                                  "-v"
#define CS_ARG_VIS_AFTER                            "-va"
#define CS_ARG_VIS_AFTER_WITHOUT_TREE               "-vawt"
#define CS_TAG_ROOT                                 "root"
// input fule
    #define CS_TAG_MAP                              "map"
        #define CS_TAG_WIDTH                        "width"
        #define CS_TAG_HEIGHT                       "height" 
        #define CS_TAG_STARTX                       "startx"
        #define CS_TAG_STARTY                       "starty"
        #define CS_TAG_FINISHX                      "finishx"
        #define CS_TAG_FINISHY                      "finishy"
        #define CS_TAG_GRID                         "grid"  
            #define CS_TAG_ROW                      "row"
    #define CS_TAG_ALGORITHM                        "algorithm"
        #define CS_TAG_SEARCHTYPE                   "searchtype"
            #define CS_TAG_RRT                      "rrt"
            #define CI_TAG_RRT                      0
            #define CS_TAG_RRT_STAR                 "rrtstar"
            #define CI_TAG_RRT_STAR                 1
        #define CS_TAG_NUMBER_OF_ITERATIONS         "numberofiterations"
        #define CS_TAG_STEP_SIZE                    "stepsize"
        #define CS_TAG_EPS                          "eps"
    #define CS_TAG_LOG                              "log"
        #define CS_TAG_PATH_FILE                    "path"
// output file
    #define CS_TAG_TIME                             "time"
    #define CS_TAG_COUNT_OF_EDGES                   "countofedges"
    #define CS_TAG_PATH_FOUND                       "pathfound"
    #define CS_TAG_RESULT_DISTANCE                  "distance"
    #define CS_TAG_RESULT_PATH                      "path"
        #define CS_TAG_NODE                         "node"
            #define CS_ATR_X                        "x"
            #define CS_ATR_Y                        "y"
            #define CS_ATR_NUMBER                   "number"

    