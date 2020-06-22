#pragma once

#include "Fresh/Core/Input.h"

namespace Fresh {

	class WindowsInput : public Input {

	protected:

		bool IsKeyPressedImpl(int keycode) override;
		bool IsMouseButtonPressedImpl(int keycode) override;
		float GetMouseXImpl() override;
		float GetMouseYImpl() override;
		std::pair<float, float> GetMousePosImpl() override;

	};

}
