//
//  MscConstants.h
//  Under-n-Over
//
//  Created by Paul Cefalu on 1/30/14.
//
//

#ifndef Under_n_Over_MscConstants_h
#define Under_n_Over_MscConstants_h

#define FULL_SCREEN_HORIZONTAL_SCALE         2.4
#define FULL_SCREEN_VERTICAL_SCALE           2.0

#define PTM_RATIO                            32
#define GRAVITY_RATIO                        9.8
#define WORLD_TO_SCREEN(n)                   ((n) * PTM_RATIO)

#define DEFAULT_VELOCITY_ITERATIONS          8
#define DEFAULT_POSITION_ITERATIONS          3

#define DEFAULT_FIXTURE_DENSITY              1.0f
#define DEFAULT_FIXTURE_FICTION              0.6f
#define DEFAULT_FIXTURE_RESTITUTION          0.8f


#endif  // Under_n_Over_MscConstants_h
