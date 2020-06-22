#include "frpch.h"

#include "LayerStack.h"

namespace Fresh {

	LayerStack::~LayerStack() {
		for (Layer* layer : m_Layers) {
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushOverlay(Layer* overlay) {
		m_Layers.emplace_back(overlay);
		overlay->OnAttach();
	}

	void LayerStack::PushLayer(Layer* layer) {
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
		layer->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer) {
		LayerIterator it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
		if (it != m_Layers.end()) {
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* layer) {
		LayerIterator it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), layer);
		if (it != m_Layers.end()) {
			m_Layers.erase(it);
		}
	}
}