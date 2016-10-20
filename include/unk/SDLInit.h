/* Unknown Engine Project */

namespace unk {

    /**
     * @brief Each SDL flag correspond to every SDL subsystem to be initialized.
     */
	enum class SDLInitFlags {
		TIMER, 
		AUDIO, 
		VIDEO, 
		JOYSTICK, 
		HAPTIC,
		GAMECONTROLLER, 
		EVENTS, 
		EVERYTHING, 
		NOPARACHUTE;
	}

	/// @brief Initializes SDL with the specified flags.
    void InitializeSDL(std::vector<SDLInitFlags> flags = { EVERYTHING });
}