struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const GetConfig::Duration::T::Value &
	inputTimeout () const;

	GetConfig::Duration::T::Value &
	inputTimeout ();

	const GetConfig::Duration::T::Value &
	outputTimeout () const;

	GetConfig::Duration::T::Value &
	outputTimeout ();

	const GetConfig::Duration::T::Value &
	roundTripTimeout () const;

	GetConfig::Duration::T::Value &
	roundTripTimeout ();
};
