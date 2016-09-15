/* Unknown Engine Project */

#ifndef UNK_RENDERER_H
#define UNK_RENDERER_H

class SDL_Renderer;

namespace unk {

    class Renderer {
        private:
            SDL_Renderer *SDLRenderer;

        public:
            Renderer();
            SDL_Texture *createTextureFromSurface(SDL_Surface *surface);
    };
}

#endif
