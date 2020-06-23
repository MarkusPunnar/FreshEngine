#pragma once

#include "Fresh/Core/Layer.h"

class TestLayer : public Fresh::Layer {

public:
	TestLayer();

	void OnUpdate() override;

	void OnEvent(Fresh::Event& e) override;

	void OnAttach() override;

	void OnDetach() override;


};
