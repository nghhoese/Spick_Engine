#ifndef INPUTFIELD_H_
#define INPUTFIELD_H_

#include "UIObject.hpp"
#include <functional>
#include "Text.hpp"

namespace spic {

	/**
	 * @brief Instances of this class are clickable user interface items.
	 */
	class InputField : public UIObject {
	public:
		/**
		 * @brief Get interactable.
		 * @return interactable.
		 */
		bool GetInteractable() const { return interactable; }

		/**
		 * @brief Set interactable.
		 */
		void SetInteractable(bool interactable) { this->interactable = interactable; }

		/**
		 * @brief Get text.
		 * @return text.
		 */
		const std::string& GetText() const { return textComponent.GetText(); }

		/**
		 * @brief Set text.
		 */
		void SetText(const std::string& text) { textComponent.SetText(text); }

		/**
		 * @brief Get initial text.
		 * @return initial text.
		 */
		const std::string& GetInitialText() const { return initialText; }

		/**
		 * @brief Set initial text.
		 */
		void SetInitialText(const std::string& initialText) { this->initialText = initialText; }

		/**
		 * @brief Get placeholder text.
		 * @return placeholder text.
		 */
		const std::string& GetPlaceholderText() const { return placeholderText; }

		/**
		 * @brief Set placeholder text.
		 */
		void SetPlaceholderText(const std::string& placeholderText) { this->placeholderText = placeholderText; }

		/**
		 * @brief Get limit.
		 * @return limit.
		 */
		int GetLimit() const { return limit; }

		/**
		 * @brief Set limit.
		 */
		void SetLimit(int limit) { this->limit = limit; }

		/**
		 * @brief Register the OnValueChange handler to be used when the inputfield value is changed.
		 * @param callback The function to register, usually a lambda. But this can be
		 *        any kind of callable.
		 */
		void OnValueChange(std::string text, std::function<void()> callback) { onValueChange = callback; }

		/**
		* @brief Register the OnEndEdit handler to be used when the inputfield value editing is finished.
		* @param callback The function to register, usually a lambda. But this can be
		*        any kind of callable.
		*/
		void OnEndEdit(std::string text, std::function<void()> callback) { onEndEdit = callback; }

	private:
		/**
		 * @brief When false, the text field is not changeable.
		 */
		bool interactable;

		/**
		* @brief Textcomponent that contains editable content of this inputfield.
		*/
		Text textComponent;

		/**
		* @brief Initial text of this inputfield.
		*/
		std::string initialText;

		/**
		* @brief Text shown as placeholder in inputfield, no text shown when empty.
		*/
		Text placeholder;

		/**
		* @brief Initial text of this inputfield.
		*/
		std::string placeholderText;

		/**
		* @brief Characterlimit of inputfield
		*/
		int limit;

		/**
		 * @brief The registered change handler. Is invoked when the text content of the Input Field changes.
		 */
		std::function<void()> onValueChange;

		/**
		* @brief The registered editing ended handler. Is invoked when the user finishes editing the text content either by submitting or by clicking somewhere that removes the focus from the Input Field.
		*/
		std::function<void()> onEndEdit;
	};

}

#endif // INPUTFIELD_H_
