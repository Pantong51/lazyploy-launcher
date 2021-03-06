// Copyright 2016 Gamemakin LLC. All Rights Reserved.

#pragma once

/**
* Implements a widget for form input field labels with optional validation errors.
*/
class SLazyployLauncherFormLabel
	: public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SLazyployLauncherFormLabel)
		: _ErrorToolTipText()
		, _ErrorVisibility(EVisibility::Hidden)
		, _LabelText()
	{ }

	/** The tool tip text for the validation error icon. */
	SLATE_ATTRIBUTE(FText, ErrorToolTipText)

	/** The visibility of the validation error icon. */
	SLATE_ATTRIBUTE(EVisibility, ErrorVisibility)

	/** The text of the form label. */
	SLATE_ATTRIBUTE(FText, LabelText)

	SLATE_END_ARGS()

public:

	/**
	* Constructs the widget.
	*
	* @param InArgs The Slate argument list.
	*/
	void Construct(const FArguments& InArgs)
	{
		ChildSlot
			[
				SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Center)
						[
							SNew(SImage)
								.Image(FLazyployLauncherClientStyle::Get().GetBrush(TEXT("ProjectPicker.ErrorImage")))
								.ToolTipText(InArgs._ErrorToolTipText)
								.Visibility(InArgs._ErrorVisibility)
						]

					+ SHorizontalBox::Slot()
						.FillWidth(1.0f)
						.VAlign(VAlign_Center)
						[
							SNew(STextBlock)
								.Text(InArgs._LabelText)
								.TextStyle(FLazyployLauncherClientStyle::Get(), TEXT("ProjectPicker.Text"))
						]
			];
	}
};
